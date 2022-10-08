# def getmlr(lst): # O(n)
#     mx,l,r = -1,[],[]
#     mx=a.index(max(a))
#     return mx, a[:mx], a[mx+1:]
    # for i in lst:
    #     if i > mx:
    #         l += r+[mx] if mx != -1 else r
    #         mx = i
    #         r = []
    #     else: r += [i]
    # return mx, l, r
 

def tree(a):
	if a == []:
		return []
	i = a.index(max(a))
	ans = tree(a[:i]) + [-1] + tree(a[i+1:])
	for i in range(len(ans)): ans[i] += 1
	return ans

tn = int(input())
for _ in range(tn):
	input()
	print(*tree(list(map(int, input().split()))))

# a = 1 2 3 1 2 1
#         i
#     1 0 -1 1 0 1
#     2 1 0 2 1 2