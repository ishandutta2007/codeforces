#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*int n,m,w;
    cin >>n>>m>>w;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    while(m--)
    {
        sort(arr,arr+n);
        for(int i = 0;i<w;i++)
        {
            arr[i]++;
        }
    }
    sort(arr,arr+n);
    cout << arr[0];*/
    string s;
    int n, k;
    cin >> n >> k >> s;
    int as=0;
    string ans;
    for(int i=0; i<s.size() && as<k/2; i++){
        if(s[i]==')'){
            ans.push_back(')');
        }else if(s[i]=='('){
            ans.push_back('(');
            as++;
        }
    }
    int b=ans.size();
    for(int i=0; i<k-b; i++) ans.push_back(')');
    cout << ans;
    return 0;
}