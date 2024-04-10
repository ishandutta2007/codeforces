#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define dbg(x) cout << #x << " : " << (x) << '\n';
#define mn(a, b) (a < b ? a : b)
#define mx(a, b) (a > b ? a : b)
#define all(v)  (v).begin(), (v).end()
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 105

int mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,x;
    cin >> a >> b >> x;
    string res="0";
    int cont0=1,cont1=0;
    for(int i=0;i<x;i++)
    {
        if(i&1)
        {
            cont0++;
            res=res+"0";
        }
        else
        {
            cont1++;
            res=res+"1";
        }
    }
    if(cont0<=a)
    {
        for(int i=cont0;i<a;i++)
            res="0"+res;

        if(res[res.size()-1]=='0')
        {
            for(int i=cont1;i<b;i++)
            {
                res[res.size()-1]='1';
                res=res+"0";
            }
        }
        else
        {
            for(int i=cont1;i<b;i++)
                res=res+"1";
        }
        db(res)
    }
    else
    {
        res="1";
        cont0=0,cont1=1;
        for(int i=0;i<x;i++)
        {
            if(i&1)
            {
                cont1++;
                res=res+"1";
            }
            else
            {
                cont0++;
                res=res+"0";
            }
        }
        for(int i=cont1;i<b;i++)
            res="1"+res;

        if(res[res.size()-1]=='1')
        {
            for(int i=cont0;i<a;i++)
            {
                res[res.size()-1]='0';
                res=res+"1";
            }
        }
        else
        {
            for(int i=cont0;i<a;i++)
                res=res+"0";
        }
        db(res)
    }
    return 0;
}