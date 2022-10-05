X = int(input())
Xo = X

factor = []

test = 2
while test * test <= X:
    curr = 0
    while X % test == 0:
        X //= test
        curr += 1

    if curr > 0:
        factor.append(pow(test,curr))
    test += 1
    
if X > 1:
    factor.append(X)

X = Xo

poss = [1]
for fact in factor:
    for v in poss[:]:
        if fact * v * fact * v <= X:
            poss.append(fact * v)

best = max(poss)
print(best, X//best)