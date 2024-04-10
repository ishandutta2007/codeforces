#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

long long int a1 , b1 , a2 , b2 , ans;
map<long long int , long long int>  mp;
map<long long int , long long int>  smp;
map< pair<long long int , long long int> , bool>  mark;
map<pair<long long int , long long int> , bool>	smark;
map<long long int , long long int>	amp;
map<long long int , long long int>	bmp;
queue< pair<long long int , long long int> >  saf;
long long int t1 , t2 , t3 , t4;

void input(){
    cin >> a1 >> b1;
    cin >> a2 >> b2;
}

void check(long long int a , long long int b , long long int c , long long int d){
    if ( a % c != 0 || b % d != 0 ) return;
    
    long long int aa , bb;
    if ( c == 1 )   aa = a;
    else    aa = a - a / c;
    if ( d == 1 )   bb = b;
    else    bb = b - b / d;
    long long int n = aa * bb;
    if ( mark[ make_pair(aa , bb) ] == 1 )	   return;

    mark[ make_pair(aa , bb) ] = 1;
    saf.push( make_pair(aa , bb) );
    if ( mp[n] == 0 && a1 * b1 != n ){
	 mp[n] = mp[a * b] + 1;
	 amp[n] = aa;
	 bmp[n] = bb;
    }	     
    
}

void bfs(long long int a , long long int b){
    mark[ make_pair(a , b) ] = 1;
    mp[a * b] = 0;
    amp[a * b] = a;
    bmp[a * b] = b;
    saf.push(make_pair(a , b));

    pair<long long int , long long int> front;
    long long int size;
    while ( !saf.empty() ){
	 size = saf.size();
	 for ( long long int i = 0 ; i < size ; i++ ){
	     front = saf.front();
    
	     check(front.first , front.second , 1 , 2);
	     check(front.first , front.second , 2 , 1);
	     check(front.first , front.second , 1 , 3);
	     check(front.first , front.second , 3 , 1);

	     saf.pop();
	 }
    }
}

void scheck(long long int a , long long int b , long long int c , long long int d){
    if ( a % c != 0 || b % d != 0 ) return;

    long long int aa , bb;
    if ( c == 1 )   aa = a;
    else    aa = a - a / c;
    if ( d == 1 )   bb = b;
    else    bb = b - b / d;
    long long int n = aa * bb;
    if ( smark[ make_pair(aa , bb) ] == 1 )	   return;
    
    smark[ make_pair(aa , bb) ] = 1;
    saf.push( make_pair(aa , bb) );
    if ( smp[n] == 0 && a2 * b2 != n )
	 smp[n] = smp[a * b] + 1;
}

void sec_dfs(long long int a , long long int b){
    smark[ make_pair(a , b) ] = 1;
    smp[a * b] = 0;
    saf.push(make_pair(a , b));

    pair<long long int , long long int> front;
    long long int size;
    while( !saf.empty() ){
	 size = saf.size();
	 for ( long long int i = 0 ; i < size ; i++ ){
	     front = saf.front();
	 
	     if ( mp[front.first * front.second] != 0 || a1 * b1 == front.first * front.second ){
		  if ( ans == -1 || ans > mp[front.first * front.second] + smp[front.first * front.second] ){
		      ans = mp[front.first * front.second] + smp[front.first * front.second]; 
		      t3 = front.first;
		      t4 = front.second;
		      t1 = amp[front.first * front.second];
		      t2 = bmp[front.first * front.second];
		  }   
	     }
	 
	     scheck(front.first , front.second , 1 , 2);
	     scheck(front.first , front.second , 2 , 1);
	     scheck(front.first , front.second , 1 , 3);
	     scheck(front.first , front.second , 3 , 1);
	     
	     saf.pop();
	 }
    }

    
}

void show_Ans(){
    if ( ans == -1 )	   cout << -1 << endl;
    else{
	 cout << ans << endl;
	 cout << t1 << " " << t2 << endl;
	 cout << t3 << " " << t4 << endl;
    }
}

int main(){
    ans = -1;
    input();
    bfs(a1 , b1);
    sec_dfs(a2 , b2);
    show_Ans();
    return 0;
}