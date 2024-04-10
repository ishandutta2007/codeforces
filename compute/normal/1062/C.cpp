#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1e5+7;
long long tree[maxn];
long long two[maxn];
void add(int pos)
{
    while(pos<maxn)
    {
        tree[pos]++;
        pos+=pos&-pos;
    }
}
int sum(int pos)
{
    int ret=0;
    while(pos>0)
    {
        ret+=tree[pos];
        pos-=pos&-pos;
    }
    return ret;
}
void db()
{
    two[0]=1;
    for(int i=1;i<maxn;i++)
    {
        two[i]=two[i-1]*2%mod;
    }
}
int main()
{
    db();
    memset(tree,0,sizeof(tree));
    int n,q;
    scanf("%d%d",&n,&q);
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='1')
            add(i);
    }
    int l,r;
    while(q--)
    {
        scanf("%d%d",&l,&r);
        int one=sum(r)-sum(l-1);
        int zero=(r-l+1)-one;
        long long ans=(two[one]-1+(two[one]-1)*(two[zero]-1)%mod+mod)%mod;
        printf("%lld\n",ans);
    }

}