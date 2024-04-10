#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int q(int i,int j,string s)
{
    cout << s << " " << i << " " << j << "\n";
    cout.flush();
    int x;
    cin >> x;
    if(x==-1) exit(0);
    return x;
}

int bit(int a,int i){return ((a>>i)&1);}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a=0,b=0,c=0;
    int aband=q(1,2,"AND");
    int abxor=q(1,2,"XOR");
    int bcand=q(2,3,"AND");
    int bcor=q(2,3,"OR");
    int acand=q(1,3,"AND");
    for(int i=0;(1<<i)<n;i++)
    {
        if(bit(abxor,i)==0)
        {
            if(bit(aband,i)==1)
            {
                a+=(1<<i);
                b+=(1<<i);
                if(bit(bcand,i)==1) c+=(1<<i);
            }
            else
            {
                if(bit(bcor,i)==1) c+=(1<<i);
            }
        }
        else
        {
            if(bit(acand,i)==0&&bit(bcand,i)==0)
            {
                if(bit(bcor,i)==1) b+=(1<<i);
                else a+=(1<<i);
            }
            else
            {
                c+=(1<<i);
                if(bit(acand,i)==1) a+=(1<<i);
                else b+=(1<<i);
            }
        }
    }
    vector<int> res(n+1,0);
    res[1]=a;
    res[2]=b;
    res[3]=c;
    for(int i=4;i<=n;i++) res[i]=(q(i-1,i,"XOR")^res[i-1]);
    cout << "! ";
    for(int i=1;i<=n;i++) cout << res[i] << " \n";
    cout.flush();
    return 0;
}