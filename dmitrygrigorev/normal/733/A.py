string = input()
distance = 0
counter = 1
for i in range(len(string)):
    element = string[i]
    if element not in ["A", "E", "I", "O", "U", "Y"]:
        counter += 1
    else:
        distance = max(distance, counter)
        counter = 1
print(max(distance, counter))