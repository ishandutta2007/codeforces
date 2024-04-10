#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector <int> ar;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(x) ar.push_back(x);
        }
        for(int i=0; i<n-1; i++)
        {
            vector <int> ar2;
            if(ar.size() != n-i and ar.size()) ar2.push_back(ar[0]);
            for(int a=1; a<ar.size(); a++)
            {
                int x=ar[a]-ar[a-1];
                if(x) ar2.push_back(x);
            }
            sort(ar2.begin(), ar2.end());
            ar=ar2;
        }
        if(ar.size()) printf("%d\n", ar[0]);
        else printf("0\n");
    }
}