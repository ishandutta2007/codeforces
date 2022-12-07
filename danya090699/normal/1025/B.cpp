#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][2];
    for(int a=0; a<n; a++) scanf("%d%d", &ar[a][0], &ar[a][1]);
    vector <int> de;
    for(int i=0; i<2; i++)
    {
        for(int a=2; a*a<=ar[0][i]; a++)
        {
            if(ar[0][i]%a==0)
            {
                de.push_back(a);
                while(ar[0][i]%a==0) ar[0][i]/=a;
            }
        }
        if(ar[0][i]>1) de.push_back(ar[0][i]);
    }
    for(int a=1; a<n; a++)
    {
        vector <int> de2;
        for(int b=0; b<de.size(); b++)
        {
            if(ar[a][0]%de[b]==0 or ar[a][1]%de[b]==0) de2.push_back(de[b]);
        }
        de.clear();
        for(int b=0; b<de2.size(); b++) de.push_back(de2[b]);
    }
    if(de.size()) cout<<de[0];
    else cout<<-1;
}