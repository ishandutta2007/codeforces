#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;
struct edge{
    int x,y,w;
};
bool operator<(edge x,edge y){
    return x.w<y.w || (x.w==y.w && x.x<y.x) || (x.w==y.w && x.x==y.x && x.y<y.y);
}
int i,j,k,n,m,q;
multiset<edge>All,D[maxn];
set<edge>use;
map<pair<int,int>,int>M;
multiset<ll>ANS;
void work(){
    // 
    long long Ans=0;
    Ans=0ll+(*All.begin()).w+(*++All.begin()).w+(*++++All.begin()).w;

    // 
    auto E=*use.begin();
    int Num=0;
    for(auto t:use){
        ++Num;if(Num>=12)exit(1);
        // cerr<<"t:"<<t.x<<' '<<t.y<<" | "<<E.x<<' '<<E.y<<endl;
        if(t.x!=E.x && t.y!=E.x && t.x!=E.y && t.y!=E.y){
            Ans=min(Ans,0ll+E.w+t.w);
            break;
        }
    }
    // cerr<<"OK! "<<Ans<<endl;

    // 
    int X=E.x,Y=E.y,Cnt0=1;
    for(auto e1=D[X].begin();e1!=D[X].end()&&Cnt0<=3;Cnt0++,++e1){
        int Cnt1=1;
        for(auto e2=D[Y].begin();e2!=D[Y].end()&&Cnt1<=3;Cnt1++,++e2){
            if((*e1).x!=(*e2).x && (*e1).y!=(*e2).x && (*e1).x!=(*e2).y && (*e1).y!=(*e2).y)
                Ans=min(Ans,0ll+(*e1).w+(*e2).w);
        }
    }

    printf("%lld\n",Ans);
}
bool check(edge t){
    int Num=0,Cnt;
    Cnt=1;for(auto e=D[t.x].begin();e!=D[t.x].end()&&Cnt<=3;Cnt++,++e)if((*e).y==t.y)++Num;
    Cnt=1;for(auto e=D[t.y].begin();e!=D[t.y].end()&&Cnt<=3;Cnt++,++e)if((*e).x==t.x)++Num;
    // cerr<<"Check "<<t.x<<' '<<t.y<<" Num="<<Num<<endl;
    return Num==2;
}
void INSERT(int x,int y,int z){
    All.insert((edge){x,y,z});
    M[make_pair(x,y)]=z;int Cnt;
    Cnt=1;for(auto e=D[x].begin();e!=D[x].end()&&Cnt<=3;Cnt++,++e)if(check(*e))if(use.find(*e)!=use.end())use.erase(*e);
    Cnt=1;for(auto e=D[y].begin();e!=D[y].end()&&Cnt<=3;Cnt++,++e)if(check(*e))if(use.find(*e)!=use.end())use.erase(*e);
    D[x].insert((edge){x,y,z});D[y].insert((edge){x,y,z});
    Cnt=1;for(auto e=D[x].begin();e!=D[x].end()&&Cnt<=3;Cnt++,++e)if(check(*e))use.insert(*e);
    Cnt=1;for(auto e=D[y].begin();e!=D[y].end()&&Cnt<=3;Cnt++,++e)if(check(*e))use.insert(*e);
}
void ERASE(int x,int y,int z){
    // cerr<<"ERASE."<<endl;
    All.erase(All.find((edge){x,y,z}));int Cnt;
    Cnt=1;for(auto e=D[x].begin();e!=D[x].end()&&Cnt<=3;Cnt++,++e)if(check(*e))if(use.find(*e)!=use.end())use.erase(*e);
    Cnt=1;for(auto e=D[y].begin();e!=D[y].end()&&Cnt<=3;Cnt++,++e)if(check(*e))if(use.find(*e)!=use.end())use.erase(*e);
    D[x].erase((edge){x,y,z});D[y].erase((edge){x,y,z});
    // cerr<<"------"<<endl;
    Cnt=1;for(auto e=D[x].begin();e!=D[x].end()&&Cnt<=3;Cnt++,++e)if(check(*e))use.insert(*e);
    Cnt=1;for(auto e=D[y].begin();e!=D[y].end()&&Cnt<=3;Cnt++,++e)if(check(*e))use.insert(*e);
}
int main(){
    cin>>n>>m;
    for(i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x>y)swap(x,y);
        INSERT(x,y,z);
    }
    work();
    cin>>q;
    for(i=1;i<=q;i++){
        int op;
        scanf("%d",&op);
        if(op==0){
            int x,y,z;
            scanf("%d%d",&x,&y);
            if(x>y)swap(x,y);
            z=M[make_pair(x,y)];
            ERASE(x,y,z);
        }else{
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(x>y)swap(x,y);
            INSERT(x,y,z);
        }
        work();
    }
}