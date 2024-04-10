#include <iostream>
#include <string>

using namespace std;
string s;
int n, a[1005];
char c;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n=s.size();
    s=s+"z";
    for(int i=0;i<n;i++)
    {
        if((s[0]<s[i] && s[i+1]<=s[0])||(s[0]>s[i] && s[i+1]>s[i]))
        {
            a[i]=1;
            c=s[0];
            s[0]=s[i];
            s[i]=c;
        }
    }
    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
    return 0;
}