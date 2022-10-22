    #include <bits/stdc++.h>
     
    using namespace std;
    int t, n;
    vector <int> v;
     
    int main()
    {freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
        cin >> t;
        for(int i=0;i<t;i++)
            {
                cin >> n;
                v.push_back(1-n%2);
            }
        for(int i=0;i<t;i++)
            cout << v[i] << endl;
        return 0;
    }