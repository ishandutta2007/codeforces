#include<bits/stdc++.h>
using namespace std;
#define N 200001
bool bo[N];
int prime[N],pri=0;
void Init(){
    int i,j;
    for(i=2;i<N;++i){
        if(!bo[i]){
            prime[++pri]=i;
            for(j=i+i;j<N;j+=i){
                bo[j]=1;
            }
        }
    }
}
int cnt=0,a[N];
vector<int>num, b[N];
vector<long long>sum;
multiset<long long>M;
void init(int d,int n){
    int i,j;
    long long s=0;
    for(i=1;i<=d;++i){
        s=0;
        num.push_back(d);
        for(j=i;j<=n;j+=d){
            s+=1LL*a[j];
            b[j].push_back(cnt);
        }
        sum.push_back(s);
        M.insert(sum[cnt]*num[cnt]);
        ++cnt;
    }
}
void putans(){
    printf("%lld\n",*M.rbegin());
}
void work(){
    int n,q,i,d,p,x;
    M.clear();
    sum.clear();
    num.clear();
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    cnt=0;
    for(d=1;d<=pri;++d){
        if(n%prime[d]==0){
            //printf("%d\n",prime[d]);
            init(n/prime[d],n);
        }
    }
    putans();
    int detla;
    for(i=1;i<=q;++i){
        scanf("%d%d",&p,&x);
        detla = x-a[p];
        a[p]=x;
        for(auto id:b[p]){
            M.erase(M.find(sum[id]*num[id]));
            sum[id] += detla;
            M.insert(sum[id]*num[id]);
        }
        putans();
    }
    for(i=1;i<=n;++i)b[i].clear();
}
int main(){
    Init();
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}