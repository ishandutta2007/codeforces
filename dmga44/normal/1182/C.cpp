#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,char> pic;
#define MAXN 100005

string s[MAXN];
map<char,int> mm;
vector<int> m[MAXN*10][6];
vector<int> mmm[MAXN*10];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mm['a']=1;
    mm['e']=2;
    mm['i']=3;
    mm['o']=4;
    mm['u']=5;

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        char l='a';
        int cont=0;
        for(auto y : s[i])
            if(mm[y])
            {
                l=y;
                cont++;
            }
        mmm[cont].push_back(i);
        m[cont][mm[l]].push_back(i);
    }

    int m1=0,m2=0;
    for(int i=1;i<MAXN*10;i++)
    {
        int s1=0;
        for(int j=0;j<6;j++)
        {
            m1+=(m[i][j].size()-(m[i][j].size()&1));
            s1+=(m[i][j].size()&1);
        }
        m2+=(s1-(s1&1));
    }

    while(m1>m2)
    {
        m2+=2;
        m1-=2;
    }

    m1/=2;
    m2=m1;
    db(m1)
    vector<int> v1;
    for(int i=1;i<MAXN*10;i++)
    {
        for(int j=0;j<6;j++)
        {
            int x=min((int)(m[i][j].size()/2),m1);
            m1-=x;
            for(int u=0;u<x;u++)
            {
                v1.push_back(m[i][j][u*2]);
                v1.push_back(m[i][j][(u*2)+1]);
                mk[m[i][j][u*2]]=1;
                mk[m[i][j][u*2+1]]=1;
            }
        }
    }

    vector<int> v2;
    for(int i=1;i<MAXN*10;i++)
    {
        int c=0;
        for(auto y : mmm[i])
            if(mk[y])
                c++;
        int plu=(mmm[i].size()-c)/2;
        plu=min(plu,m2);
        m2-=plu;
        plu*=2;
        for(int j=0;j<mmm[i].size() && plu;j++)
            if(!mk[mmm[i][j]])
            {
                v2.push_back(mmm[i][j]);
                plu--;
            }
    }

    for(int i=0;i<v1.size();i++)
        cout << s[v2[i]] << ' ' << s[v1[i]] << '\n';

    return 0;
}