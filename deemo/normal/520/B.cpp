#include<iostream>
#include<queue>

using namespace std;

int n , m;
const int max_n = 2 * 10 * 1000 + 1000;
queue<int>  saf;
bool mark[max_n];
int ans;

void bfs(){
    saf.push(n);
    mark[n] = 1;
    
    int size , x , temp;
    while( !saf.empty() ){
	 ans += 1;
	 size = saf.size();
	 for ( int i = 0 ; i < size ; i++ ){
	     x = saf.front();
	     if ( x <= m )
		  if ( mark[x * 2] == 0 ){
		      mark[x * 2] = 1;
		      saf.push(x * 2);	  
		      if ( x * 2 == m )   return;
		  }
	     if ( x - 1 >= 1 )
		  if ( mark[x - 1] == 0 ){
		      mark[x - 1] = 1;
		      saf.push(x - 1);
		      if ( x - 1 == m )   return;
		  }
	     saf.pop();
	 }
    }

}

int main(){
    cin >> n >> m;
    
    bfs();
    cout << ans << endl;

    return 0;
}