#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<pair<int,int> > st;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i!=0 && j!=0 && j>i && j-i==1 && i%2==0 && (n-j+1)%2==0) st.insert(make_pair(i,n-j+1));
        }
    }
    if(st.size()!=0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}