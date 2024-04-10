#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

string t[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int dif(string &a, string &b){
    int cnt = 0;
    for(int i = 0; i < 7; i++){
        if(a[i] == '1' and b[i] == '0')
            return -1;
        cnt += (a[i] != b[i]);
    }
    return cnt;
}

const int MM = 2002;
int n, k;
short last[MM][MM];
string s[MM];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    
    memset(last, -1, sizeof last);
    last[0][0] = 0;
    
    for(int i = n; i > 0; i--){
        cin>>s[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            for(short l = 0; l < 10; l++){
                int v = dif(s[i], t[l]);
                if(v != -1 and v <= j and last[i-1][j-v] != -1){
                    last[i][j] = max(last[i][j], l);
                }
            }
//            cout<<last[i][j]<<' ';
        }
//        cout<<'\n';
    }
    int st = last[n][k];
//    cout<<"st "<<st<<endl;
    if(st == -1){
        cout<<"-1\n";
        return 0;
    }
    
    for(int i = n; i > 0; i--){
        cout<<st;
        int v = dif(s[i], t[st]);
        k -= v;
        st = last[i-1][k];
    }
    
    return 0;
}
/*

4 0
1011101
1011101
1011101
1011101
 
 
4 5
1110111
1110111
1110111
1110111
 

 */