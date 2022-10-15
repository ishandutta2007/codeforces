#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int n;
int v[N];
int p[N];
int l[N],r[N];
int st[N],vf;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                p[v[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
                while(vf && v[i]>v[st[vf]])
                {
                        vf--;
                }
                l[i]=st[vf]+1;
                st[++vf]=i;
        }
        st[0]=n+1;
        vf=0;
        for(int i=n;i>=1;i--)
        {
                while(vf && v[i]>v[st[vf]])
                {
                        vf--;
                }
                r[i]=st[vf]-1;
                st[++vf]=i;
        }
        int res=0;
        for(int i=1;i<=n;i++)
        {
                int st1=l[i];
                int dr1=i-1;
                int st2=i+1;
                int dr2=r[i];
                int len1=dr1-st1;
                int len2=dr2-st2;
                int kk;
                if(len1<len2)
                {
                        for(int j=st1;j<=dr1;j++)
                        {
                                kk=p[v[i]-v[j]];
                                if(st2<=kk && kk<=dr2)
                                {
                                        res++;
                                }
                        }
                }
                else
                {
                        for(int j=st2;j<=dr2;j++)
                        {
                                kk=p[v[i]-v[j]];
                                if(st1<=kk && kk<=dr1)
                                {
                                        res++;
                                }
                        }
                }
        }
        cout<<res<<"\n";
        return 0;
}
/**

**/