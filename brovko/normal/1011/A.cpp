#include <iostream>

using namespace std;
int n, k, b[26], p, l, s;
char c;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        b[(int)c-(int)'a']++;
    }
    p=0;
    l=0;
    s=0;
    while(p<26 && l<k)
    {
        if(b[p]>0)
        {
            l++;
            s=s+p+1;
            p+=2;
        }
        else p++;
    }
    if(l<k)
        cout << -1;
    else
    cout << s;
    return 0;
}