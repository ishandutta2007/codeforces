#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int a[26];
    for (int i=0;i<26;i++)
        a[i]=0;
    char c[10];
    cin >> c;
    for (int i=0;c[i]!='\0';i++)
          a[(int)c[i]-(int)'a']++;
    for (int i=25;i>=0;i--)
        if (a[i]!=0)
        {
                    char t = (char)((int)'a'+i);
                    for (int j=0;j<a[i];j++)
                        cout << t;
                    return 0;
        }
}