#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

struct Bomb{
    int first , second;
};

int n;
long long int ans;
vector< Bomb > vec;

bool help( Bomb a , Bomb b ){
    if ( abs(a.second) < abs(b.second) )  return true;
    if ( abs(a.second) == abs(b.second) && abs(a.first) < abs(b.first) )    return true;
    else    return false;

}

void input(){
    scanf("%d" , &n);//cin >> n;
    Bomb b;    

    for ( int i = 0 ; i < n ; i++ ){
	 scanf("%d" , &b.first);//cin >> b.first >> b.second;
	 scanf("%d" , &b.second);

	 if ( b.first == 0 || b.second == 0 ) ans += 4;
	 else	  ans += 6;

	 vec.push_back( b );
    }
    sort( vec.begin() , vec.end() , help );

}

void get_Ans(){
    cout << ans << endl;
    int x , y;

    for ( int i = 0 ; i < n ; i++ ){	   
	 x = vec[i].first;
	 y = vec[i].second;

	 if ( x != 0 ){
	     printf("%d " , 1);//cout << 1 << " ";
	     printf("%d " , abs(x));//cout << abs(x) << " ";
	     if ( x > 0 )	printf("%c\n" , 'R');//cout << "R" << endl;
	     else    printf("%c\n" , 'L');//cout << "L" << endl;

	 }	 
	 
	 if ( y != 0 ){
	     printf("%d " , 1);//cout << 1 << " ";
	     printf("%d " , abs(y));//cout << abs(y) << " ";
	     if ( y > 0 )	printf("%c\n" , 'U');//cout << "U" << endl;
	     else    printf("%c\n" , 'D');//cout << "D" << endl;
	 
	 }

	 printf("%d\n" , 2);//cout << 2 << endl;
	
	 if ( x != 0 ){
	     printf("%d " , 1);//cout << 1 << " ";
	     printf("%d " , abs(x));//cout << abs(x) << " ";
	     if ( x > 0 )	printf("%c\n" , 'L');//cout << "L" << endl;
	     else    printf("%c\n" , 'R');//cout << "R" << endl;

	 }    
	 
	 if ( y != 0 ){
	     printf("%d " , 1);//cout << 1 << " ";   
	     printf("%d " , abs(y));//cout << abs(y) << " ";
	     if ( y > 0 )	printf("%c\n" , 'D');//cout << "D" << endl;
	     else    printf("%c\n" , 'U');//cout << "U" << endl;

	 }
 
	 printf("%d\n" , 3);//cout << 3 << endl;
    }

}

int main(){
    input();
    get_Ans();
    return 0;

}