#include <iostream>

using namespace std;
char a[1000];
int i, k, s, b[26];
int main()
{
    i=0;
    k=0;
    while(a[i]!='}')
    {
        cin >> a[i];
        if(a[i]>='a'&&a[i]<='z')
        {
            b[(int)a[i]-(int)'a']=1;
            i++;
            k++;
        }
    }
    s=0;
    for(int i=0;i<26;i++)
        s+=b[i];
    cout << s;
    return 0;
}