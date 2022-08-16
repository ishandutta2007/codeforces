#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <queue>
using namespace std;

// #define int long long

int main(){
	long long n;
	cin >> n;
	priority_queue<long long> q1;
	priority_queue<long long> q2;

	long long score = 0;
	long long sum1=0;
	long long sum2=0;
	for (long long i = 0; i<n; i++){
		long long t;
		cin >> t;
		q1.push(t);
		sum1+=t;
		// s1.add(t);
	}
	
	for (long long i = 0; i<n; i++){
		long long t;
		cin >> t;
		q2.push(t);
		sum2+=t;
		// s2.add(t);
	}

	while(!q1.empty() && !q2.empty()){		
		if(q1.top()>q2.top()){
			score+=q1.top();
			q1.pop();
		}
		else{
			q2.pop();
		}
	if(!q1.empty() && !q2.empty()){
		if(q2.top()>q1.top()){
			score-=q2.top();
			q2.pop();
		}
		else{
			q1.pop();
		}
	}
	else if(q1.empty()){
		score-=q2.top();
			q2.pop();
	}
	else{
			q1.pop();
		}

	}
	while(!q2.empty()){
		q2.pop();
		if(!q2.empty()){
		score-=q2.top();
		q2.pop();
	}
	}

	while(!q1.empty()){
		score+=q1.top();
		q1.pop();
		if(!q1.empty())
		q1.pop();
	}
	cout << score <<endl;
}