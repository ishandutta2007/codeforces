#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool mark[1000005];
int main()
{
    int n;
    cin >> n;
    int need = n;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        mark[a[i]] = true;
        while(need >= 1 && mark[need]){
            cout << need << " ";
            need --;
        }
        cout << "\n";
    }
    
}