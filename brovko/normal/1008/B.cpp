#include <iostream>

using namespace std;
int n, w[100000], h[100000];

int main()
{
    bool f=true;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> w[i] >> h[i];
    h[0]=max(w[0], h[0]);
    for(int i=1;i<n;i++)
        if(max(w[i], h[i])<=h[i-1])
        h[i]=max(w[i], h[i]);
    else h[i]=min(w[i], h[i]);
    for(int i=1;i<n;i++)
        if(h[i]>h[i-1])
            f=false;
    if(f)
        cout << "YES";
    else cout << "NO";
    return 0;
}