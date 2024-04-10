#include<bits/stdc++.h>
#define N 300005
#define M 50
using namespace std;
int a[N];
struct qry{
    int type;
    int l,r,x,y,k;
}b[N];
bitset<N+N> c[50];
vector<int>vec;
int getid(int x){
    return (lower_bound(vec.begin(), vec.end(), x)-vec.begin());
}
int B[50][N];
inline int lowbit(const int x){
    return x&-x;
}
void add(int id,int x,int d){
    for(;x<N;x+=lowbit(x))B[id][x]+=d;
}
void ADD(int i,int ai, int d){
    int id=getid(ai);
    for(int ii=0;ii<M;++ii){
        if(c[ii][id]){
            add(ii, i, d);
        }
    }
}
int qry(int id,int x){
    int res=0;
    for(;x;x-=lowbit(x))res+=B[id][x];
    return res;
}
bool chk(int l,int r,int k){
    int i;
    for(i=0;i<M;++i){
        int tmp=qry(i,r)-qry(i,l-1);
        tmp%=k;
        if(tmp)return 0;
    }
    return 1;
}
int main(){
    //srand(time(0));
    std::mt19937 rng(std::random_device{}());
    int n,q,i,j;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        vec.push_back(a[i]);
    }
    for(i=1;i<=q;++i){
        scanf("%d",&b[i].type);
        if(b[i].type==1){
            scanf("%d%d",&b[i].x,&b[i].y);
            vec.push_back(b[i].y);
        }
        else scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].k);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(i=0;i<M;++i){
        for(j=0;j<vec.size();++j){
            if(rng()&1)c[i].set(j);
        }
    }
    for(i=1;i<=n;++i){
        ADD(i,a[i],1);
    }
    for(i=1;i<=q;++i){
        if(b[i].type==1){
            ADD(b[i].x, a[b[i].x], -1);
            a[b[i].x]=b[i].y;
            ADD(b[i].x, a[b[i].x], 1);
        }
        else{
            if((b[i].r-b[i].l+1)%b[i].k){
                puts("NO");
            }
            else if(chk(b[i].l,b[i].r,b[i].k))puts("YES");
            else puts("NO");
        }
    }
    return 0;
}