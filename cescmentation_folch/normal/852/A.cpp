#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;

string out(int sum){
    string s;
    s = "";
    while (sum > 0){
        s.push_back('0'+sum%10);
        sum /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

string tall;
int ans;
bool back(string s, int p, int sum, vector<bool> add, int last){
    //cerr << s << " " << s.size() << " " << p << endl;
    if (p == s.size()){
        sum += last;
        int csum = sum;
        int sumd = 0;
        while (csum > 0){
            sumd += csum%10;
            csum /= 10;
        }
       // cerr << "ep " << sum << " " << last << " " << sumd << endl;
        
        if (sumd < 10){
            cout << tall << endl;
            for (int i = 0; i < int(s.size()); ++i){
                cout << s[i];
                if (add[i]) cout << "+";
            }
            cout << endl;
            
            string s= out(sum);
            for (int i = 0; i < int(s.size()); ++i){
                if (i) cout << "+";
                cout << s[i];
                sum += s[i]-'0';
            }
            cout << endl;
            exit(0);
        }
        return false;
    }
    
    if (back(s, p+1, sum, add, last*10 + (s[p]-'0'))) return true;
    if (p != s.size() -1){
        add[p] = true;
        return back(s, p+1, sum + last*10 + (s[p]-'0'), add, 0);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >>n ;
    int sum = 0;
    string s;
    cin >> s;
    
    //srand(time(NULL));
    srand(12345);
    while (true){
        int cnt = 0;
        int sum = 0, last = 0;
        tall = "";
        for (int i = 0; i < int(s.size()); ++i){
            last = last*10 + s[i]-'0';
            tall.push_back(s[i]);
            if ((cnt >= 2 or rand()%2 == 1) and i != s.size()-1){
                tall.push_back('+');
                sum += last;
                cnt = 0;
                last = 0;
            }
            else ++cnt;
        }
        sum += last;
        //cerr << sum << endl;
        back(out(sum), 0, 0, vector<bool>(s.size(), false), 0);
        
    }
    
    return 0;
    for (int i = 0; i < n; ++i){
        if (i) cout << "+";
        cout << s[i];
        sum += s[i]-'0';
    }
    cout << endl;
    
    s = out(sum);
    //coses
    
    
    sum = 0;
    for (int i = 0; i < int(s.size()); ++i){
        if (i) cout << "+";
        cout << s[i];
        sum += s[i]-'0';
    }
    cout << endl;
    
    s = "";
    while (sum > 0){
        s.push_back('0'+sum%10);
        sum /= 10;
    }
    reverse(s.begin(), s.end());
    
    for (int i = 0; i < int(s.size()); ++i){
        if (i) cout << "+";
        cout << s[i];
        sum += s[i]-'0';
    }
    cout << endl;
}