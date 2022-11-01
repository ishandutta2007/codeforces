#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string,int> m={{"polycarp",1}};
    int d=1;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin >> a >> b >> b;
        for(char &c:a) c=tolower(c);
        for(char &c:b) c=tolower(c);
        m[a]=m[b]+1;
        d=max(d,m[a]);
    }
    cout << d << endl;
    return 0;
}