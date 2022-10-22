#include <iostream>
#include <string>

using namespace std;
int n, T;
string s;

int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> n;
        cin >> s;
        int f=1;
        for(int j=0;j<n-1;j++)
            if((int)s[j]-(int)s[n-1-j]>2 || (int)s[j]-(int)s[n-1-j]<-2 || (int)s[j]-(int)s[n-1-j]==1 || (int)s[j]-(int)s[n-1-j]==-1)
                f=0;
        if(f==0)
        cout << "NO";
        else cout << "YES";
        cout << endl;
    }
    return 0;
}