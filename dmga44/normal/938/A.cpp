#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s,res="";
    cin >> s;
    for(int i=0;i<n;i++)
    {
        string ss=" ";
        ss[0]=s[i];
        if(!i)
        {
            res=res+ss;
            continue;
        }
        else if((s[i-1]=='a' || s[i-1]=='e' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u' || s[i-1]=='y') && (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y'))
            continue;
        res=res+ss;
    }
    cout << res;
    return 0;
}