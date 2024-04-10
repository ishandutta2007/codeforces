n = int(input())
games = n - 1
massiv = [2]
while massiv[-1] <= games:
    if len(massiv) == 1:
        massiv += [4]
    else:    
        massiv += [massiv[-1] + massiv[-2] + 1]
print(len(massiv))