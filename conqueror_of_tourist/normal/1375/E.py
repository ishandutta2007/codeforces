n = int(input())
l = list(map(int, input().split()))
order = [(l[i],i) for i in range(n)]
order.sort(reverse = True)

out = []
for v, ind in order:
    for i in range(ind):
        if v < l[i]:
            out.append(str(i + 1)+' '+str(ind + 1))

print(len(out))
print('\n'.join(out))