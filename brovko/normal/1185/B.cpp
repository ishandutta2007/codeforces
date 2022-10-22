#include <iostream>
#include <string>

using namespace std;
int n, l, r, k, k1, f;
string s, t;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        cin >> t;
        l=0;
        r=0;
        f=1;
        while(l<s.size())
        {
            k=0;
            k1=0;
            while(l<s.size() &&(k==0 || s[l]==s[l-1]))
            {
                l++;
                k++;
            }
            while(r<t.size() && t[r]==s[l-1])
            {
                r++;
                k1++;
            }
            if(k>k1 || (k==0 && k1>0))
                f=0;
        }
        if(f==0 || r<t.size())
            cout << "NO";
        else cout << "YES";
        cout << endl;
    }
    return 0;
}