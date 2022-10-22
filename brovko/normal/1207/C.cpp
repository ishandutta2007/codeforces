#include <iostream>
#include <string>

using namespace std;
long long n, t, a, b, x, c;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int t1=0;t1<t;t1++)
    {
        c=0;
        x=0;
        cin >> n >> a >> b;
        cin >> s;
        long long k=0;
        while(k<n && s[k]=='0')
        {
            x++;
            k++;
        }
        if(k>=n)
            cout << n*a+(n+1)*b << endl;
        else
        {
            c+=(x+1)*a+(x+2)*b;
            while(k<n)
            {
                x=0;
                while(k<n && s[k]=='1')
                {
                    k++;
                    x++;
                }
                c+=2*x*b+x*a;
                x=0;
                while(k<n && s[k]=='0')
                {
                    k++;
                    x++;
                }
                if(k>=n)
                {
                    c+=(x+1)*a+x*b;
                    break;
                }
                else c+=min((x+1)*b+(x+2)*a, 2*x*b+x*a);
            }
            cout << c << endl;
        }
    }
    return 0;
}