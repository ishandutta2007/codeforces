#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a[4];
    for (int i=0;i<n;i++)
        cin >> a[i];
    int m;
    cin >> m;
    int pp = 100,ind =0;
    for (int i=0;i<m;i++)
    {
        int k;
        cin >> k;
        string b[k];
        for (int j=0;j<k;j++)
            cin >> b[j];
        int p = 100;
        for (int e=0;e<k;e++)
            for (int f=0;f<k;f++)
                for (int g=0;g<k;g++)
                    for (int h=0;h<k;h++)
                        if (b[e]==a[0] &&
                            (n<=1 || b[f]==a[1]) && 
                            (n<=2 || b[g]==a[2]) &&
                            (n<=3 || b[h]==a[3]))
                            {
                                  int tp = 0;
                                  if (e>f)tp++;
                                  if (e>g)tp++;
                                  if (e>h)tp++;
                                  if (f>g)tp++;
                                  if (f>h)tp++;
                                  if (g>h)tp++;
                                  if (tp<p)
                                     p = tp;
                            }
        if (p<pp)
        {
                 pp = p;
                 ind = i+1;
        }
    }
    if (ind==0)
       cout << "Brand new problem!";
    else
    {
        pp = n*(n-1)/2 - pp +1;
        cout << ind << endl;
        cout << "[:";
        for (int l=0;l<pp;l++)
            cout << "|";
        cout << ":]";
    }
    return 0;
}