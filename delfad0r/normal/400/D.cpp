#include <bitset>
#include <iostream>
#include <stack>
#include <vector>

struct edge {
	int to, cost;
	
	edge(int to_, int cost_) : to(to_), cost(cost_) { }
};

int N, M, K;
int c[500];
std::vector<edge> graph[100001];
int group[100001];
std::bitset<100001> visited;
int min_dist[500][500];

void read() {
	int sum = 1, u, v, x;
	std::cin >> N >> M >> K;
	for(int k = 0; k < K; ++k) {
		std::cin >> c[k];
		for(int i = sum; i < sum + c[k]; ++i)
			group[i] = k;
		sum += c[k];
	}
	for(int m = 0; m < M; ++m) {
		std::cin >> u >> v >> x;
		graph[u].push_back(edge(v, x));
		graph[v].push_back(edge(u, x));
	}
}

bool is_correct() {
	std::stack<int> nodes;
	int sum = 1, node;
	for(int k = 0; k < K; ++k) {
		visited.reset();
		nodes.push(sum);
		while(!nodes.empty()) {
			node = nodes.top();
			nodes.pop();
			visited[node] = true;
			for(std::vector<edge>::iterator it = graph[node].begin(); it != graph[node].end(); ++it) {
				if(it->cost == 0 && !visited[it->to]) {
					nodes.push(it->to);
				}
				else if(group[it->to] != group[node]) {
					if(min_dist[group[node]][group[it->to]] < 0 || min_dist[group[node]][group[it->to]] > it->cost)
						min_dist[group[node]][group[it->to]] = min_dist[group[it->to]][group[node]] = it->cost;
				}
				/*if(group[it->to] == k) {
					if(it->cost == 0 && !visited[it->to])
						nodes.push(it->to);
				}
				else {
					if(min_dist[k][group[it->to]] < 0 || min_dist[k][group[it->to]] > it->cost)
						min_dist[k][group[it->to]] = min_dist[group[it->to]][k] = it->cost;
				}*/
			}
		}
		
		for(int i = sum; i < sum + c[k]; ++i)
			if(!visited[i]) return false;
		
		sum += c[k];
	}
	return true;
}

void floyd_warshall() {
	for(int k = 0; k < K; ++k) {
		for(int i = 0; i < K; ++i) {
			for(int j = i + 1; j < K; ++j) {
				if(min_dist[i][k] >= 0 && min_dist[j][k] >= 0) {
					if(min_dist[i][j] < 0 || min_dist[i][k] + min_dist[j][k] < min_dist[i][j])
						min_dist[i][j] = min_dist[j][i] = min_dist[i][k] + min_dist[j][k];
				}
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	read();
	
	for(int k1 = 0; k1 < K; ++k1) {
		for(int k2 = 0; k2 < K; ++k2) {
			min_dist[k1][k2] = -1 * !(k1 == k2);
		}
	}
	
	if(is_correct()) {
		std::cout << "Yes\n";
	}
	else {
		std::cout << "No\n";
		return 0;
	}
	
	floyd_warshall();
	for(int k1 = 0; k1 < K; ++k1) {
		for(int k2 = 0; k2 < K; ++k2)
			std::cout << min_dist[k1][k2] << ' ';
		std::cout << '\n';
	} 
}