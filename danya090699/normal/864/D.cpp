//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0;
    cin>>n;
    int us[n];
    int ar[n];
    bool us2[n];
    set <int> av;
    for(int a=0; a<n; a++)
    {
        us[a]=0, us2[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar[a]--;
        us[ar[a]]++;
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0) av.insert(a);
    }
    for(int a=0; a<n; a++)
    {
        if(us[ar[a]]>1)
        {
            int va=*av.begin();

            if(va<ar[a])
            {
                us[ar[a]]--, ar[a]=va, q++;
                av.erase(av.begin());
            }
            else
            {
                if(us2[ar[a]])
                {
                    us[ar[a]]--, ar[a]=va, q++;
                    av.erase(av.begin());
                }
                else us2[ar[a]]=1;
            }
            //cout<<ar[a]<<" ";
        }
    }
    cout<<q<<"\n";
    for(int a=0; a<n; a++) cout<<ar[a]+1<<" ";
}