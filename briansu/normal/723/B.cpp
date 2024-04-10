#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const double EPS=1e-8;
const ll INF=ll(1e18);
typedef pair<int,ll> ill;
int main()
{
    int n;
    cin>>n;
    cin.ignore(1);
    string s;
    cin>>s;
    int pcnt=0;
    int longest=0;
    int wcnt=0;
    int lcnt=0;
    for(int i=0;i<n;i++)
    {
        if(pcnt)
        {
            if(s[i]=='_')
            {
                if(lcnt)wcnt++;
                lcnt=0;
            }
            else if(s[i]==')')
            {
                if(lcnt)wcnt++;
                lcnt=0;
                pcnt--;
            }
            else
            {
                lcnt++;
            }
        }
        else
        {
            if(s[i]=='_')
            {
                if(lcnt>longest)longest=lcnt;
                lcnt=0;
            }
            else if(s[i]=='(')
            {
                if(lcnt>longest)longest=lcnt;
                lcnt=0;
                pcnt++;
            }
            else
            {
                lcnt++;
            }
        }
    }
    if(lcnt>longest)longest=lcnt;
    cout<<longest<<" "<<wcnt<<endl;

}