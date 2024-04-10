#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
pair <string, int> ar[sz];
bool comp(pair <string, int> a, pair <string, int> b)
{
    int q1=a.second, q2=a.first.size()-a.second;
    int q11=b.second, q22=b.first.size()-b.second;
    return (1ll*q1*q22>1ll*q11*q2);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a].first;
        ar[a].second=0;
        for(int b=0; b<ar[a].first.size(); b++) if(ar[a].first[b]=='s') ar[a].second++;
    }
    sort(ar, ar+n, comp);
    int sq=0;
    long long an=0;
    for(int a=0; a<n; a++)
    {
        string s=ar[a].first;
        for(int b=0; b<s.size(); b++)
        {
            if(s[b]=='s') sq++;
            else an+=sq;
        }
    }
    cout<<an;
}