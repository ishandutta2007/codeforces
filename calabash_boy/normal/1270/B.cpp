#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        vector<int> a;
        while (n--){
            int x;
            cin>>x;
            a.push_back(x);
        }
        bool flag = false;
        for (int i = 0;i < a.size() - 1;i ++){
            if (abs(a[i]-a[i+1]) >= 2){
                puts("YES");
                cout<<i + 1 <<" "<< i + 2<<endl;
                flag = true;
                break;
            }
        }
        if (!flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}