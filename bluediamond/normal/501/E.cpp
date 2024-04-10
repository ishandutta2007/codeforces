#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;

int n;
int v[N],f[N];
bool e[N];
int st,dr;

bool ok(int l,int r)
{
        for(int i=1;i<=n;i++)
        {
                e[i]=0;
                f[i]=0;
        }
        for(int i=l;i<=r;i++)
        {
                e[i]=1;
                f[v[i]]++;
        }
        for(int i=1;i<n+1-i;i++)
        {
                if(e[i]==1 && e[n+1-i]==0)
                {
                        if(f[v[n+1-i]]>0)
                        {
                                f[v[n+1-i]]--;
                        }
                        else
                        {
                                return 0;
                        }
                }
                if(e[i]==0 && e[n+1-i]==1)
                {
                        if(f[v[i]]>0)
                        {
                                f[v[i]]--;
                        }
                        else
                        {
                                return 0;
                        }
                }
                if(e[i]==0 && e[n+1-i]==0 && v[i]!=v[n+1-i])
                {
                        return 0;
                }
        }
        int cntimp=0;
        for(int i=1;i<=n;i++)
        {
                if(f[i]%2==1)
                {
                        cntimp++;
                }
        }
        return (cntimp<=1);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                f[v[i]]++;
        }
        int imp=0;
        for(int i=1;i<=n;i++)
        {
                if(f[i]%2==1)
                {
                        imp++;
                }
        }
        if(imp>=2)
        {
                cout<<"0\n";
                return 0;
        }
        bool pali=1;
        for(int i=1;i<n+1-i;i++)
        {
                if(v[i]!=v[n+1-i])
                {
                        pali=0;
                }
        }
        if(pali)
        {
                ll res=n*(ll)(n+1)>>1;
                cout<<res<<"\n";
                return 0;
        }

        /**
        cout<<ok(5,5)<<"\n";
        cout<<ok(4,5)<<"\n";
        cout<<ok(3,5)<<"\n";
        cout<<ok(2,5)<<"\n";
        cout<<ok(1,5)<<"\n";

        return 0;
        **/
        /**
        cout<<ok(1,1)<<"\n";
        cout<<ok(1,2)<<"\n";
        cout<<ok(1,3)<<"\n";
        return 0;
        **/
        st=1;
        dr=n;
        while(v[st]==v[dr])
        {
                st++;
                dr--;
        }
        int lo=st;
        int hi=dr;
        int prf=-1,suf=-1;
        while(lo<=hi)
        {
                int mid=(lo+hi)>>1;
                if(ok(st,mid))
                {
                        prf=mid;
                        hi=mid-1;
                }
                else
                {
                        lo=mid+1;
                }
        }
        lo=1;
        hi=n;
        while(lo<=hi)
        {
                int mid=(lo+hi)>>1;
                ///cout<<lo<<" , "<<hi<<"\n";
                if(ok(mid,dr))
                {
                        suf=mid;
                        lo=mid+1;
                }
                else
                {
                        hi=mid-1;
                }
        }
        int cntgood=0;
        if(prf!=-1)
        {
                cntgood+=(dr-prf+1);
        }
        if(suf!=-1)
        {
                cntgood+=(suf-st+1);
        }
        ll res=cntgood*(ll)st-1+(st-1LL)*(ll)(st-1LL);
        cout<<res<<"\n";
        return 0;
}
/**

**/