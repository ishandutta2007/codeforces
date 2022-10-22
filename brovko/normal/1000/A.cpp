#include <iostream>
#include <string>
#include <map>

using namespace std;
int n, k;
string a[100], b[100], str[9];
map <string, int> ka;
map <string, int> kb;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ka[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
        kb[b[i]]++;
    }
    str[0]="L";
     str[1]="XL";
      str[2]="XXL";
       str[3]="XXXL";
        str[4]="M";
         str[5]="S";
          str[6]="XS";
           str[7]="XXS";
            str[8]="XXXS";
    for(int i=0;i<9;i++)
    {
        if(ka[str[i]]>kb[str[i]])
            k=k+ka[str[i]]-kb[str[i]];
    }
    cout << k;
    return 0;
}