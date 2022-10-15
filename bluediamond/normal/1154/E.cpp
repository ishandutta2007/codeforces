#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;

int n,k;
int v[N];
int urm[N];
int ant[N];
bool valid[N];
int p[N];
int sol[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>k;
        valid[0]=valid[n+1]=1;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
                valid[i]=1;
                urm[i]=i+1;
                ant[i]=i-1;
                p[v[i]]=i;
        }
        int curr=1;
        for(int x=n;x>=1;x--)
        {
                int poz=p[x];
                if(valid[poz]==0) continue;
                vector<int>cur;
                cur.push_back(poz);

                int lft=poz;
                int rhg=poz;

                int j=urm[poz],seen=0;
                while(j<=n && seen<k)
                {
                        if(valid[j])
                        {
                                rhg=j;
                                cur.push_back(j);
                                seen++;
                        }
                        j=urm[j];
                }
                j=ant[poz],seen=0;
                while(1<=j && seen<k)
                {
                        if(valid[j])
                        {
                                lft=j;
                                cur.push_back(j);
                                seen++;
                        }
                        j=ant[j];
                }
                int vl;
                int vr;
                if(valid[lft-1])
                {
                        vl=lft-1;
                }
                else
                {
                        vl=ant[lft-1];
                }
                if(valid[rhg+1])
                {
                        vr=rhg+1;
                }
                else
                {
                        vr=urm[rhg+1];
                }
                for(auto &j:cur)
                {
                        sol[j]=curr;
                        valid[j]=0;
                        urm[j]=vr;
                        ant[j]=vl;
                }
                curr=3-curr;
        }
        for(int i=1;i<=n;i++)
        {
                cout<<sol[i];
        }
        cout<<"\n";
        return 0;
}
/**
**/