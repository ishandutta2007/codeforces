#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
#define int long long
const int N=15;
int n;
vector<int> elems[N];
map<ll, int> where;
int last[N];
ll sum[N];
ll want;
int timestep;
bool okbase[1<<N];
bool ok[1<<N];
int what[N];
int wheere[N];

void print(int mask){
        if(okbase[mask]){
               /// ssert(mask>0);
                int i=0;
                while(!(mask&(1<<i))) i++;
                if(mask==(1<<i)){
                        what[i]=elems[i][0];
                        wheere[i]=i;
                        return;
                }
                for(int i=0;i<n;i++){
                        if(mask&(1<<i))

                for(auto&x:elems[i]){
                        timestep++;
                        int J=i,wanda=0;
                        ll X=x;
                        bool bad=0;
                        vector<int> cycle;
                        vector<int> wzz;
                        while(last[J]!=timestep){
                                last[J]=timestep;
                                wanda+=(1<<J);
                                ll need=want-(sum[J]-X);
                                if(!where.count(need)){
                                        bad=1;
                                        break;
                                }
                                int K=where[need];
                                wzz.push_back(X);
                                cycle.push_back(J);
                                X=need;
                                if(K==J){
                                        bad=1;
                                        break;
                                }
                                J=K;
                        }
                        if(J==i&&!bad&&wanda==mask&&x==X){
                            //    exit(0);
                                int k=(int)wzz.size();
                                for(int j=0;j<k;j++){
                                        wheere[cycle[j]]=cycle[(j+k-1)%k];
                                        what[cycle[j]]=wzz[j];
                                }
                                return;
                        }
                }}
                cout<<"bad : "<<mask<<"\n";
                for(int i=0;i<n;i++){
                        if(mask&(1<<i)) cout<<1;
                        else cout<<0;
                }
                exit(0);
                assert(0);
                return;
        }
        for(int mask2=(mask-1)&mask;mask2>0;mask2=(mask2-1)&mask){
                if(ok[mask2]&&ok[mask^mask2]){
                        print(mask2);
                        print(mask^mask2);
                        return;
                }
        }
       /// ssert(0);
}

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        ll S=0;
        cin>>n;
        for(int i=0;i<n;i++){
                int k;
                cin>>k;
                elems[i].resize(k);
                for(auto&x:elems[i]){
                        cin>>x;
                        sum[i]+=x;
                        assert(!where.count(x));
                        where[x]=i;
                        S+=x;
                }
        }

        if(S%n){
                cout<<"No\n";
                return 0;
        }

        want=S/n;

        for(int i=0;i<n;i++){
                if(sum[i]==want){
                        okbase[1<<i]=1;
                }
        }

        for(int i=0;i<n;i++){
                for(auto&x:elems[i]){
                        timestep++;
                        /// if i loses x => it wants "want-(sum[i]-X)"
                        int J=i,mask=0;
                        ll X=x;
                        bool bad=0;
                        while(last[J]!=timestep){
                                last[J]=timestep;
                                mask+=(1<<J);
                                ll need=want-(sum[J]-X);
                                X=need;
                                if(!where.count(need)){
                                        bad=1;
                                        break;
                                }
                                int K=where[need];
                                if(K==J){
                                        bad=1;
                                        break;
                                }
                                J=K;
                        }
                        if(J==i&&!bad&&x==X){
                                okbase[mask]=1;
                        }
                }
        }

        for(int mask=0;mask<(1<<n);mask++){
                ok[mask]=okbase[mask];
                for(int mask2=(mask-1)&mask;mask2>0;mask2=(mask2-1)&mask){
                        ok[mask]|=(ok[mask2]&&ok[mask^mask2]);
                }
        }
        if(!ok[(1<<n)-1]){
                cout<<"No\n";
                return 0;
        }
        cout<<"Yes\n";
        print((1<<n)-1);
        for(int i=0;i<n;i++){
                cout<<what[i]<<" "<<wheere[i]+1<<"\n";
        }
        return 0;
}