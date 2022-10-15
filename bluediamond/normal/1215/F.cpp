#include <bits/stdc++.h>

using namespace std;

bool home = 1;


void myasert(bool sh){
        if(!sh){
                cout<<"bad\n";
                exit(0);
        }
}

struct SAT{
        struct Edge{
                int _from;
                int _to;
                int _head;
                Edge(int a,int b,int c) {
                        _from=a;
                        _to=b;
                        _head=c;
                }
                int from(){
                        return _from;
                }
                int to(){
                        return _to;
                }
                int head(){
                        return _head;
                }
        };
        int temporal=0;
        int n;
        vector<int> head;
        vector<Edge> edges;
        vector<bool> vis;
        vector<int> order;
        vector<int> when;

        SAT(int n) : n(n),vis(2*n,0),when(2*n),head(2*n,-1) {
        }
        void addImplication(int a,int b,int aneg,int bneg){
                a--;
                b--;
                myasert(0<=a&&a<n);
                myasert(0<=b&&b<n);
                edges.push_back(Edge(2*a+aneg, 2*b+bneg, head[2*a+aneg]));
                edges.push_back(Edge(2*b+1-bneg, 2*a+1-aneg, head[2*b+1-bneg]));
                head[2*a+aneg]=(int)edges.size()-2;
                head[2*b+1-bneg]=(int)edges.size()-1;
        }



        void dfs(int a){
                vis[a]=1;
                for(int i=head[a];i!=-1;i=edges[i].head()){
                        int b=edges[i].to();
                        if(!vis[b]) dfs(b);
                }
                order.push_back(a);
        }

        void place(int a){
                vis[a]=1;
                when[a]=temporal;
                for(int i=head[a];i!=-1;i=edges[i].head()){
                        int b=edges[i].to();
                        if(!vis[b]) place(b);
                }
        }



        vector<int> get(){


                /// CTC
                for(int a=0;a<2*n;a++){
                        if(!vis[a]){
                                vector<pair<int,int>> stk={{a,head[a]}};
                                vis[a]=1;
                                while(!stk.empty()){
                                        int a=stk.back().first,i=stk.back().second;
                                       // myasert(0<=a&&a<2*n);
                                        if(i==-1) {stk.pop_back(); order.push_back(a); continue;}
                                        int b=edges[i].to();
                                        if(edges[i].head()!=-1){
                                         //       myasert(i>edges[i].head());
                                        }
                                        stk.back().second=edges[i].head();
                                        if(!vis[b]){
                                             ///   myasert(0<=b&&b<2*n);
                                                vis[b]=1;
                                                stk.push_back({b, head[b]});
                                        }

                                }
                        }
                }
                if(n==1200000){
                 ///       exit(0);
                }
                for(int i=0;i<2*n;i++){
                        vis[i]=0;
                        head[i]=-1;
                }
                for(int i=0;i<(int)edges.size();i++){
                        int from=edges[i].from(),to=edges[i].to();
                        swap(from,to);
                        edges[i]=Edge(from,to,head[from]);
                        head[from]=i;
                }
                reverse(order.begin(),order.end());
                for(auto&i:order){
                        if(!vis[i]){
                                temporal++;
                                place(i);
                        }
                }
                vector<int> sol;
                for(int i=0;i<n;i++){
                        int a=2*i,b=2*i+1;
                        if(when[a]==when[b]) return {};
                        sol.push_back(when[a]>when[b]);
                }
                return sol;
        }
};

int main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        int n,p,M,m;
        cin>>n>>p>>M>>m;

        /**

        variables:
        p people
        <= M frequencies
        >= M frequencies

        pt 1<=i<M : either (f<=i) or (f>=i+1)


        **/
        int init=p+2*M;

        SAT sat(init);


        /// 1<=x<=p
        /// 1<=y<=p
        /// 1<=f<=M
        for(int i=1;i<=n;i++){
                int x,y;
                cin>>x>>y;
                /// !x -> y
                sat.addImplication(x,y,1,0);
        }
        for(int i=1;i<=p;i++){
                int l,r;
                cin>>l>>r;
                /// if we take i => l<=f<=r
                if(l-1>=1){
                        sat.addImplication(p+(l-1),i,0,1);
                }
                if(r+1<=M){
                        sat.addImplication(p+M+(r+1),i,0,1);
                }
        }


        for(int i=1;i<M;i++){
                sat.addImplication(p+i,p+M+i+1,1,0);

                /// if f<=i => f<=i+1
                sat.addImplication(p+i,p+i+1,0,0);
                /// if f>=i+1 => f>= i
                sat.addImplication(p+M+i+1,p+M+i,0,0);
        }

        for(int i=1;i<=m;i++){
                int x,y;
                cin>>x>>y;
                /// x -> !y
                sat.addImplication(x,y,0,1);
        }


        vector<int> sol=sat.get();


        if(sol.empty()){
                cout<<"-1\n";
                return 0;
        }
        int t=-1;

       /// exit(0);


        for (int i=1;i<=M;i++){
                if(sol[p+i-1]&&sol[p+M+i-1]) {
                        t=i;
                }
        }
        vector<int> guys;
        for(int i=1;i<=p;i++){
                if(sol[i-1]){
                        guys.push_back(i);
                }
        }
        cout<<(int)guys.size()<<" "<<t<<"\n";
        for(auto&g:guys){
                cout<<g<<" ";
        }
        cout<<"\n";
        return 0;
}