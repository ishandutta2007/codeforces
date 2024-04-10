#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e6+7;
int n,lm;
int l[N],r[N];
bool e[N];
int k1[N],k2[N];
vector <int> ug;
vector <int> ugs;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>lm;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                ug.push_back(x);
                if(e[x]==0)
                {
                        e[x]=1;
                        l[x]=i;
                }
                r[x]=i;
        }
        ugs=ug;
        sort(ugs.begin(),ugs.end());
        if(ug==ugs)
        {
                ll rs=lm*(lm+1LL)/2;
                cout<<rs<<"\n";
                return 0;
        }
        int st=0,DR=0;
        while(st+1<=lm)
        {
                if(e[st+1]==0)
                {
                        st++;
                }
                else
                {
                        if(DR<l[st+1])
                        {
                                st++;
                                DR=r[st];
                        }
                        else
                        {
                                break;
                        }
                }
                k1[st]=DR;
        }
        int dr=lm+1,ST=n+1;
        while(dr-1>=1)
        {
                if(e[dr-1]==0)
                {
                        dr--;
                }
                else
                {
                        if(r[dr-1]<ST)
                        {
                                dr--;
                                ST=l[dr];
                        }
                        else
                        {
                                break;
                        }
                }
                k2[dr]=ST;
        }
        ll res=0LL;
        res+=st;
        res+=(lm-dr+1);
        res++; /// all
       /// cout<<"init = "<<res<<"\n";
        for(int j=1;j<=st;j++)
        {
                int lo=dr,hi=lm;
                int kl=-1;
                while(lo<=hi)
                {
                        int mid=(lo+hi)/2;
                        if(k1[j]<k2[mid])
                        {
                                hi=mid-1;
                                kl=mid;
                        }
                        else
                        {
                                lo=mid+1;
                        }
                }
                if(kl==-1) continue;
                res+=(lm-kl+1);
        }

        cout<<res<<"\n";
        return 0;
}
/**

**/