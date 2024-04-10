//  228

#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(A) A.begin(), A.end()
#define pb push_back
#define fri(start , end , step)  for(int i = start; i < end ; i = i + step)
#define frj(start , end , step)  for(int j = start; j < end ; j = j + step)


using namespace std; 



int  find1(vector<ll>& vec , ll f){
	int index = 0;
	int l , r ;
	int s = vec .size();
	if (s== 0){
		return -1;
		}
	l = 0;
	r = s ;
	fri(0  , 18 ,1 ){
		int m = (l+ r)/2;
		if (vec[m] > f){
			r= m;
			}
		if (vec[m] < f){
			l = m;
			}
		if (vec[m] == f){
			//cout << m << "\n";
			return m;
			
			}
		} 
	
		return -1;
	}




int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t =1;
    //cin >> t;	
    while(t--){
		ll n;
		cin >> n;
		vector<ll> A(2*n);
		vector<vector<ll>> B(n);
		vector<vector<int>> G(n +1 );
		int y = 0;
		fri(0 , n , 1 ){
			ll a1 , a2;
			cin >> a1 >> a2;
			
			
			A[y] = a1;
			y+=1;
			A[y] = a2;
			y+=1;  
			B[i] = {a1 , a2};
			
			}
		sort(all(A));
		int i = 1;
		int j = 1;
		
		//fri(0 , A.size(), 1 )cout << A[i] << " "; 
		//cout << "\n";
		vector<ll> A1(n +1) ;
		A1[0] = A[0];
		while (i < 2*n){
			if (A[i] != A1[j - 1]){
				A1[j]= A[i];
				j++;
				}
			i++;
			}
		//fri(0 , A.size(), 1 )cout << A[i] << " "; 
		//cout << "\n";
		
		//fri(0 , A1.size(), 1 )cout << A1[i] << " "; 
		//cout << "\n";
		
		fri(0 , n, 1){
			int w1 = find1(A1,B[i][0]);
			int w2= find1(A1 ,B[i][1]);
			//cout << w1 << " " <<w2 << "\n";
			G[w1].pb(w2);
			G[w2].pb(w1);
			
			}
		/*//cout << "dd";
		fri(0 , n + 1 ,1){
			frj(0 , G[i].size() , 1){
				//cout << j;
				cout << G[i][j] << " ";
				}
			cout << "\n";
			//cout << "dd";
			}
		*/
		
		int start =0;
		
		fri(0 , n +1 ,1){
			
			if (G[i].size() == 1){
				
				start = i;
				break;
				}
			}
		int next = G[start][0];	
		int ls=  start;
		cout << A1[start] << " " << A1[next] << " ";
		frj(0 , n  + 1,1)	{
			fri(0 , G[next].size() ,1 ){
				if (G[next][i] != ls){
					//cout << i << "good " << next;
					cout << A1[G[next][i]] << " ";
					ls = next;
					next = G[next][i];
					}
				
				}
			
			
			
			
			
			
			
			
			
			
			}
		cout<< "\n"	;
			
		
		
    }


    return 0;
}