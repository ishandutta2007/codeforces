//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], pref[n], su=0, all=0, be;
    vector <int> v1;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(ar[a]==1000) v1.push_back(a);
        all+=ar[a];
        pref[a]=ar[a];
        if(a>0) pref[a]+=pref[a-1];
    }
    be=all;
    for(int a=0; a<n; a++)
    {
        if(ar[a]==2000)
        {
            be=min(be, su+max(0, all-su-su/10));
            int p=upper_bound(v1.begin(), v1.end(), a)-v1.begin();
            if(p<v1.size())
            {
                p=v1[p];
                int va=(p-a)*2000;
                int lef=su/10-va, add=0;
                if(lef<0)
                {
                    add-=lef, lef=0;
                }
                lef+=100, add+=1000;
                be=min(be, su+add+max(0, all-pref[p]-lef));
            }
        }
        else
        {
            be=min(be, su+max(0, all-su-su/10));
            for(int b=a+1; b<n; b++)
            {
                if(ar[b]==1000) break;
                int lef=su/10-1000, add=0;
                if(lef<0)
                {
                    add-=lef, lef=0;
                }
                lef+=200*(b-a), add+=2000*(b-a);
                be=min(be, su+add+max(0, all-pref[b]-lef));
            }
        }
        su+=ar[a];
    }
    cout<<be;
}