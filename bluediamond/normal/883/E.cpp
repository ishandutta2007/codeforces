#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+7;

int l;
string s;

bool know[1000];

int m,n=0;
string a[N];

bool valid(string str)
{
        for(int i=0;i<l;i++)
        {
                if(know[str[i]-'a'] && s[i]=='*')
                {
                        return 0;
                }
        }
        for(int i=0;i<l;i++)
        {
                if(s[i]!='*' && s[i]!=str[i])
                {
                        return 0;
                }
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>l;
        cin>>s;
        cin>>m;
        for(auto &ch:s)
        {
                if(ch=='*') continue;
                know[ch-'a']=1;
        }
        for(int i=1;i<=m;i++)
        {
                string str;
                cin>>str;
                if(valid(str))
                {
                        a[++n]=str;
                }
        }
        int rez=0;
        for(int lol=0;lol<26;lol++)
        {
                char ch=('a'+lol);
                int cont=0;
                for(int i=1;i<=n;i++)
                {
                        for(int p=0;p<l;p++)
                        {
                                if(s[p]!='*') continue;
                                if(a[i][p]==ch)
                                {
                                        cont++;
                                        break;
                                }
                        }
                }
                if(cont==n)
                {
                        rez++;
                }
        }
        cout<<rez<<"\n";

        return 0;
}
/**

!
*   * *     *

a
b
c

**/