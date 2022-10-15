#include <iostream>

using namespace std;

const int N=100;
int n,v[N+5];
char s[N+5];
int best=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin.get();
    cin.getline(s,N+5);
    for(int i=0;i<n;i++)
        v[i+1]=s[i]-'A';
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            int cnt=0;
            for(int k=1;k<n;k++)
            {
                if(v[k]==i && v[k+1]==j)
                    cnt++;
            }
            best=max(best,cnt);
        }
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            int cnt=0;
            for(int k=1;k<n;k++)
            {
                if(v[k]==i && v[k+1]==j)
                    cnt++;
            }
            if(best==cnt)
            {
                cout<<char(i+'A')<<char(j+'A');
                return 0;
            }
        }
    return 0;
}
/**
**/