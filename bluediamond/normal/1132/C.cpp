#include <bits/stdc++.h>

using namespace std;

const int N=5000+7;

int n,q;
int l[N];
int r[N];
int kek[N];
int cnt1[N];
int cnt2[N];

int get1(int l,int r)
{
        return cnt1[r]-cnt1[l-1];
}

int get2(int l,int r)
{
        return cnt2[r]-cnt2[l-1];
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>q;
        for(int i=1;i<=q;i++)
        {
                cin>>l[i]>>r[i];
                kek[l[i]]++;
                kek[r[i]+1]--;
        }
        int lol=0;
        for(int i=1;i<=n;i++)
        {
                kek[i]+=kek[i-1];
                cnt1[i]=cnt1[i-1]+(kek[i]==1);
                cnt2[i]=cnt2[i-1]+(kek[i]==2);
                lol+=(kek[i]!=0);
        }
        int rs=(1<<30);
        for(int i=1;i<=q;i++)
        {
                for(int j=i+1;j<=q;j++)
                {
                        int l1=l[i],r1=r[i];
                        int l2=l[j],r2=r[j];
                        int a=max(l1,l2),b=min(r1,r2);
                        int cur;
                        cur=get1(l1,r1)+get1(l2,r2);
                        if(a<=b)
                        {
                                cur+=get2(a,b);
                        }
                        rs=min(rs,cur);
                }
        }
        cout<<lol-rs<<"\n";
        return 0;
}