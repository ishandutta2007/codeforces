#include <iostream>

using namespace std;
int n, k, b[128], val, k1;
char s[400000];

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        {
            cin >> s[i];
            b[(int)s[i]]++;
        }
    if(k<n)
    {
        for(int i=(int)'a';i<=(int)'z';i++)
        {
            if(b[i]>=k && k!=0)
            {
                val=i;
                k1=k;
                k=0;
            }
            else if(k!=0)
                k=k-b[i];
        }
        for(int i=0;i<n;i++)
        {
            if((int)s[i]<val)
                s[i]='#';
            if((int)s[i]==val && k1>0)
            {
                s[i]='#';
                k1--;
            }
        }
        for(int i=0;i<n;i++)
        if(s[i]!='#')
            cout << s[i];
    }
}