#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], pr=0;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ar[a]=x-pr, pr=x;
    }
    vector <int> sp;
    for(int a=1; a<=n; a++)
    {
        int ok=1;
        for(int b=0; b<a; b++)
        {
            int cu=ar[b];
            for(int c=b; c<n; c+=a) if(ar[c]!=cu) ok=0;
        }
        if(ok) sp.push_back(a);
    }
    cout<<sp.size()<<"\n";
    for(int a=0; a<sp.size(); a++) cout<<sp[a]<<" ";
}