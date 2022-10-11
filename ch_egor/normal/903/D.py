def main():
	n = int(input())
	arr = list(map(int, input().split()))

	cnt = dict()
	ss = dict()
	for i in range(n):
		cnt[arr[i]] = 0
		cnt[arr[i] - 1] = 0
		cnt[arr[i] + 1] = 0
		ss[arr[i] - 1] = 0
		ss[arr[i] + 1] = 0
		ss[arr[i]] = 0

	sm = 0
	ans = 0
	for i in range(n):
		ans -= sm
		ans += i * arr[i]
		ans -= cnt[arr[i] - 1] * arr[i]
		ans -= cnt[arr[i] + 1] * arr[i]
		ans += ss[arr[i] + 1]
		ans += ss[arr[i] - 1]
		
		sm += arr[i]
		cnt[arr[i]] += 1
		ss[arr[i]] += arr[i]

	print(ans)

main()