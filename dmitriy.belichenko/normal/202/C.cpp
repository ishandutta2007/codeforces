#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
int x ;
cin >> x;
if(x == 3) cout << 5 << "\n";
else
for(int i=1; ;i += 2)
{
    if(x <= ( i * i + 1) / 2 )
    {
        cout << i << "\n";
        break;
     }
}
 return 0; 
}