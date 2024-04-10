#include <iostream>
#include <cstring>
using namespace std;
const int nmax=50000;
char s[nmax+5];
int n,nr;
int ap[50];
int main()
{
    cin.getline(s,nmax+5);
    n=strlen(s);
    int start=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='?')
        {
            int x=s[i]-'A';
            if(ap[x])
            {
                while(1)
                {
                    if(s[start]=='?')
                    {
                        start++;
                        continue;
                    }
                    ap[s[start]-'A']--;
                    start++;
                    if(s[start-1]-'A'==x)
                        break;

                }
            }
            ap[x]++;
        }
        if(i-start+1==26)
        {
            for(int j=0;j<start;j++)
            {
                if(s[j]=='?')
                    cout<<"A";
                else
                    cout<<s[j];
            }
            for(int j=start;j<=i;j++)
            {
                if(s[j]=='?')
                {
                    for(int l=0;l<26;l++)
                        if(ap[l]==0)
                        {
                            ap[l]=1;
                            cout<<char(l+'A');
                            break;
                        }
                }
                else
                    cout<<s[j];
            }
            for(int j=i+1;j<n;j++)
            {
                if(s[j]=='?')
                    cout<<"A";
                else
                    cout<<s[j];
            }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
/**

**/