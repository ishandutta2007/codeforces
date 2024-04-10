    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define x first
    #define y second
    #define mp make_pair
    #define db double
    #define pb push_back
    #define all(a) a.begin(), a.end()
    int n, m;
    int colour(int a, int b){
    	return ((a+b)%2);
    }
    int enx=-100, eny=-100;
    int d[1000][1000];
    vector<pair<int, int> > mv = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    bool can_eat(int a, int b, int c, int e){
    	for (int i=0;i<8;i++) if (a+mv[i].first==c && b+mv[i].second == e) return true;
    		return false;
    }
    int get_dist(int a, int b, int c, int e){
    	a--, b--, c--, e--;
    	for (int i=0;i<n;i++) for (int j=0; j < m; j++) d[i][j] = -1;
    	d[a][b] = 0;
    	queue<pair<int, int> > q;
    	q.push({a, b});
    	while (q.size()){
    		pair<int, int> p = q.front();
    		q.pop();
    		int x = p.first, y = p.second;
    		for (int i=0; i < mv.size(); i++){
    			int X = x+mv[i].first, Y = y+mv[i].second;
    			if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
    			if (d[X][Y] != -1) continue;
    			d[X][Y] = d[x][y] + 1;
    			q.push({X, Y});
    		}
    	}
    	return d[c][e];
    }
    void move(int a, int b, int c, int e, bool white, bool finish){
    	get_dist(c, e, a, b);
    	a--, b--, c--, e--;
    	while (a != c || b != e){
    		if (white){
    			if (can_eat(a+1, b+1, enx, eny)){
    				cout << enx << " " << eny << endl;
    				exit(0);
    			}
    			int cur = d[a][b];
    			for (int i=0; i < mv.size(); i++){
    				int x = a+mv[i].first, y = b+mv[i].second;
    				if (x < 0 || x >= n || y < 0 || y >= m) continue;
    				if (d[x][y] >= cur) continue;
    				a=x, b=y;
    				cout << x+1 << " " << y+1 << endl;
    				break;
    			}
    			if (a==c && b==e){
    				if (finish) exit(0);
    			}
    			int t, q;
    			cin >> t >> q;
    			enx=t, eny=q;
    		}
    		else{
    			int t, q;
    			cin >> t >> q;
    			enx=t, eny=q;
    			int cur = d[a][b];
    			if (can_eat(a+1, b+1, enx, eny)){
    				cout << enx << " " << eny << endl;
    				exit(0);
    			}
    			for (int i=0; i < mv.size(); i++){
    				int x = a+mv[i].first, y = b+mv[i].second;
    				if (x < 0 || x >= n || y < 0 || y >= m) continue;
    				if (d[x][y] >= cur) continue;
    				a=x, b=y;
    				cout << x+1 << " " << y+1 << endl;
    				break;
    			}
    			if (a==c && b==e){
    				if (finish) exit(0);
    			}
    		}
    	}
    }
    main(){
        srand(time(NULL));
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int xw, yw, xb, yb;
        cin >> n >> m >> xw >> yw >> xb >> yb;
        int A = get_dist(xw, yw, xb, yb);
        if (A==1){
        	cout << "WHITE" << endl;
        	cout << xb << " " << yb << endl;
        	exit(0);
        }
        bool good_first;
        if (colour(xw, yw) == colour(xb, yb)) good_first = false;
        else good_first = true;
        if (good_first){
        	int dist_my = get_dist(xw, yw, n/2, m/2), dist_his = get_dist(xw, yw, n/2+1, m/2), kek = get_dist(xb, yb, n/2+1, m/2);
        	if (dist_his <= kek+1){
        		cout << "WHITE" << endl;
        		move(xw, yw, n/2+1, m/2, 1, 0);
        		move(n/2+1, m/2, n/2, m/2, 1, 1);
        		return 0;
        	}
        	if (dist_my <= kek){
        		cout << "WHITE" << endl;
        		move(xw, yw, n/2, m/2, 1, 1);
        		return 0;
        	}
        	cout << "BLACK" << endl;
        	move(xb, yb, n/2+1, m/2, 0, 1);
        	return 0;
        }
        else{
        	int dist_my = get_dist(xb, yb, n/2+1, m/2), dist_his = get_dist(xb, yb, n/2, m/2), kek = get_dist(xw, yw, n/2, m/2);
        	if (dist_his <= kek){
        		cout << "BLACK" << endl;
        		move(xb, yb, n/2, m/2, 0, 0);
        		move(n/2, m/2, n/2+1, m/2, 0, 1);
        		return 0;
        	}
        	if (dist_my <= kek-1){
        		cout << "BLACK" << endl;
        		move(xb, yb, n/2+1, m/2, 0, 1);
        		return 0;
        	}
        	cout << "WHITE" << endl;
        	move(xw, yw, n/2, m/2, 1, 1);
        	return 0;
        }
    }