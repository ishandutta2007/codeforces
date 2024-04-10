//  228

#include <bits/stdc++.h>
#define pb push_back
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define fr first
#define sc second
using namespace std;
int main()
{
    ///system("color a") ;
    ///freopen("input.txt" , "r" , stdin );
    ///freopen("output.txt", "w" , stdout );
    ///_K_I_N_G_
    speed ;
    ///Autor of the greatest code :: Ahmadjon Murtazoev
    string s ;
    cin >> s ;
    ll ans = 0 , q = 0 ;
    for ( ll i = 0 ; i<s.size() ; i ++ )
    {
        if ( s[i] == s[i-1] )
            q ++ ;
        if ( q == 5 || s[i] != s[i-1] )
        {
            q = 0 ;
            ans ++ ;
        }
    }
    cout << ans << endl ;
	return 0 ;
}