#include <iostream>
#include <vector>

using namespace std;
int n, bs[128], bt[128];
char s[50], t[50];
vector <int> v;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        bs[(int)s[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        bt[(int)t[i]]++;
    }
    bool f=false;
    for(int i=0;i<128;i++)
    {
        if(bs[i]!=bt[i])
            f=true;
    }
    if(f)
    {
        cout << -1;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(s[j]!=t[i])
            j++;
        while(j!=i)
        {
            v.push_back(j);
            j--;
            swap(s[j], s[j+1]);
        }
    }
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    return 0;
}