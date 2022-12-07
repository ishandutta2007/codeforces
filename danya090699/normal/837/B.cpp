//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, rq=0, bq=0, gq=0, ok=0;
    cin>>n>>m;
    char ar[n][m];
    vector <int> ve;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            cin>>ar[a][b];
            if(a==0 and b==0) ve.push_back(1);
            else
            {
                int pr=(a*m)+b-1;
                if(ar[pr/m][pr%m]==ar[a][b]) ve.back()++;
                else ve.push_back(1);
            }
            if(ar[a][b]=='R') rq++;
            if(ar[a][b]=='B') bq++;
            if(ar[a][b]=='G') gq++;
        }
    }
    if(ve.size()==3 and rq==bq and bq==gq and rq%m==0) ok=1;
    ve.clear();
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(a==0 and b==0) ve.push_back(1);
            else
            {
                int pr=(a*n)+b-1;
                if(ar[pr%n][pr/n]==ar[b][a]) ve.back()++;
                else ve.push_back(1);
            }
        }
    }
    if(ve.size()==3 and rq==bq and bq==gq and rq%n==0) ok=1;
    if(ok) cout<<"YES";
    else cout<<"NO";
}